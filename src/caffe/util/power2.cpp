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

template< typename Dtype>
double weightCluster_zero( Dtype weight, double m ){
    if( weight > 0.0 && weight < m)
        weight = pow( weight, 2 );
    else if( weight >= m && weight < 1.0)
        weight = sqrt( weight );
    else if( weight <= 0 )
        weight = -pow(weight, 2);
    else if( abs( weight - 1.0 ) <= 1e-4 )
        weight = 1.0;
    else if( abs( weight ) <= 1e-8 )
        weight = 0.0;
    return (Dtype)weight;
}

template double weightCluster_zero<double>( double weight, double m);
template double weightCluster_zero<float>( float weight, double m);
template double weightCluster_zero<int>( int weight, double m );
template double weightCluster_zero<unsigned int>( unsigned int weight, double m );
