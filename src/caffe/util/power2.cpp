/*************************************************************************
	> File Name: src/caffe/util/power2.cpp
	> Author: OUC_LiuX
	> Mail: liuxiang@stu.ouc.edu.cn
	> Created Time: Fri 18 May 2018 04:09:35 PM CST
 ************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;
#include "caffe/util/power2.hpp"
#include "caffe/common.hpp"

template< typename Dtype>
Dtype weightCluster_zero( Dtype weight ){
    if( weight > 0.0 && weight < 1.0)
        weight *= 1.001;
    else if( weight > 1.0 )
        weight *= 0.999;
    else if( weight <= 0 )
        weight *=0.999;
    else if( abs( weight - 1.0 ) <= 1e-5 )
        weight = 1.0;
    else if( abs( weight ) <= 1e-5 )
        weight = 0.0;
    return (Dtype)weight;
}

template< typename Dtype>
void update_diff( int count, Dtype* diff, bool* mask ){
    for( int i = 0; i < count; i ++ )
        diff[ i] *= mask[ i];
}

template double weightCluster_zero<double>( double weight );
template float weightCluster_zero<float>( float weight);
template int weightCluster_zero<int>( int weight );
template unsigned int weightCluster_zero<unsigned int>( unsigned int weight );

template<> 
void update_diff<double>( int count, double* diff, bool* mask);
template<> 
void update_diff<float>( int count, float* diff, bool* mask);
template<>
void update_diff<int>( int count, int* diff, bool* mask );
template<>
void update_diff<unsigned int>( int count, unsigned int* diff, bool* mask );
