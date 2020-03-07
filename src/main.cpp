//
// Created by dev on 1/11/20.
//
#include <iostream>
#include <kalman.h>
#include "./Eigen/Dense"
#include <math.h>

using namespace Eigen;

Vector4d predictPos(Matrix4d A, Vector4d prevPos){
    return A*prevPos;
}

Matrix4d predictCov(Matrix4d A, Matrix4d P, Matrix4d Q){
    return A*P*A.transpose()*Q;
}

int main(int argc, char** argv){
    float dt = 1; //Delta Zeit
    MatrixXd P(4,4);
    MatrixXd Q(4,4);
    MatrixXd A(4,4);
    MatrixXd B(4,4);
    MatrixXd H(4,2);
    MatrixXd R(2,2);
    MatrixXd I(4,4);
    VectorXd x(4);
    VectorXd t_next(4);
    VectorXd t(4);
    x<<0,0,10,0;
    t<<0,0,1,2;
    P<<10,0,0,0,
        0,10,0,0,
        0,0,10,0,
        0,0,0,10;
    A<<1,0, dt, 0,
        0,1,0,dt,
        0,0,1,0,
        0,0,0,1;
    Q<<1/4*pow(dt,4), 1/4*pow(dt,4), 1/2*pow(dt,3), 1/2*pow(dt,3),
        1/4*pow(dt,4), 1/4*pow(dt,4), 1/2*pow(dt,3), 1/2*pow(dt,3),
        1/2*pow(dt,3), 1/2*pow(dt,3), pow(dt,2), pow(dt,2),
        1/2*pow(dt,3), 1/2*pow(dt,3), pow(dt,2), pow(dt,2);
    B<< 0,0,0,0,
        0,0,0,0,
        0,0,0,0,
        0,0,0,0;
    H<< 0,0,1,0,
        0,0,0,1;
    R<< 10,0,
        0,10;
    I<<Matrix4d::Identity();
    t_next=A*t;

    x=predictPos(A,x);
    P=predictCov(A,P,Q);

    std::cout<<P<<std::endl;
    std::cout<<x<<std::endl;

    float x_prev = 3.3;
    float dx = 1.2;
    float dev_pv=0.15;
    float variance=0.3;
    float meas_dev=0.1;
    float dist = 4.83;

    float x_expected = x_exp(x_prev,dx);
    float dev_expected = deviation_exp(dev_pv, variance);
    float kalman_gainv= kalman_gain(dev_expected, meas_dev);
    float x_measure=x_meas(x_expected, kalman_gainv, dist);
    float deviation_measure=deviation_meas(kalman_gainv, dev_expected);


}