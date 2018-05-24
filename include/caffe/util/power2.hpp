/*************************************************************************
	> File Name: include/caffe/util/power2.hpp
	> Author: OUC_LiuX
	> Mail: liuxiang@stu.ouc.edu.cn
	> Created Time: Fri 18 May 2018 04:09:36 PM CST
 ************************************************************************/

#include "caffe/util/math_functions.hpp"
#include "caffe/common.hpp"

template< typename Dtype>
Dtype weightCluster_zero( Dtype weight );

template< typename Dtype>
void update_diff( int, Dtype*, bool* );
