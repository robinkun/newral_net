#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double X, double eps) {
  return 1.0f / (1.0f + exp(-eps * X));
}

int main(void) {
  FILE *fp;
  double w[100];
  double t[100]; //theta
  int tmp = 0;
  double eps;

  fp = fopen("./weight.dat", "r");
  if(fp == NULL) return 1;
  for(;fgetc(fp) != '=';) {
  }
  char moji[100];
  for(int j = 0; (tmp = fgetc(fp)) != '\n' && tmp != EOF; j++) {
    moji[j] = tmp;
  }
  eps = atof(moji);
  for(int i = 0; i < 6; i++) {
    for(;fgetc(fp) != '=';) {
    }
    for(int j = 0; (tmp = fgetc(fp)) != '\n' && tmp != EOF; j++) {
      moji[j] = tmp;
    }
    w[i] = atof(moji);
  }
  for(int i = 0; i < 3; i++) {
    for(;fgetc(fp) != '=';) {
    }
    for(int j = 0; (tmp = fgetc(fp)) != '\n' && tmp != EOF; j++) {
      moji[j] = tmp;
    }
    t[i] = atof(moji);
  }

  double x1 = 1.0, x2 = 1.0;
  double temp = 0.0;
  double y[3];

  y[0] = function(w[2]*x1+w[3]*x2 - t[1], eps);
  printf("%f\n", y[0]);
  y[1] = function(w[4]*x1+w[5]*x2 - t[2], eps);
  printf("%f\n", y[1]);
  y[2] = function(w[0]*y[0]+w[1]*y[1] - t[0], eps);
  printf("%f\n", y[2]);

  return 0;
}
