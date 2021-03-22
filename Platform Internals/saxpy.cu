#include <iostream>
#include <math.h>

__global__
void saxpy(int n, float a, float * x, float * y)
{
  int i = blockIdx.x*blockDim.x + threadIdx.x;
//  printf("i = %d \n", i);
  if (i < n){
    y[i] = a*x[i] + y[i];
  }
}


int main(void) {
  int N = 1<<20;

  float *x; // = new float[N*sizeof(float)];
  float *y; // = new float[N*sizeof(float)];
  
  x = (float*)malloc(N*sizeof(float));
  y = (float*)malloc(N*sizeof(float));
  
  float *d_x, *d_y;

  // initialize x and y arrays on the host
  for (int i = 0; i < N; i++) {
    x[i] = 1.0f;
    y[i] = 2.0f;
  }

  cudaMalloc(&d_x, N*sizeof(float));
  cudaMalloc(&d_y, N*sizeof(float));
  
  cudaMemcpy(d_x, x, N*sizeof(float), cudaMemcpyHostToDevice);
  cudaMemcpy(d_y, y, N*sizeof(float), cudaMemcpyHostToDevice);

  saxpy<<<4096,256>>>(N, 2.0f, d_x, d_y);
  
  // Wait for GPU to finish before accessing on host
  cudaMemcpy(y, d_y, N*sizeof(float), cudaMemcpyDeviceToHost);
  cudaDeviceSynchronize();
  
  // Check for errors (all values should be 3.0f)
  float maxError = 0.0f;
  for (int i = 0; i < N; i++)
    maxError = fmax(maxError, fabs(y[i]-4.0f));
  std::cout << "Max error: " << maxError << std::endl;

	

  // Free memory
  delete x;
  delete y;
  cudaFree(d_x);
  cudaFree(d_y);

  return 0;
}
