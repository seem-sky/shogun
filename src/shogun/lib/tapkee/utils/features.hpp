/* This software is distributed under BSD 3-clause license (see LICENSE file).
 *
 * Copyright (c) 2012-2013 Vladyslav Gorbatiuk
 */

#ifndef TAPKEE_FEATURES_H_
#define TAPKEE_FEATURES_H_

/* Tapkee includes */
#include <shogun/lib/tapkee/defines.hpp>
 /* End of Tapkee includes */

namespace tapkee 
{
namespace tapkee_internal
{

template<class RandomAccessIterator, class FeaturesCallback>
DenseMatrix dense_matrix_from_features(const FeaturesCallback& features,
									const RandomAccessIterator& begin, 
									const RandomAccessIterator& end)
{
	DenseMatrix matrix(features.dimension(), end-begin);
	DenseVector feature_vector(features.dimension());

	for (RandomAccessIterator iter=begin; iter!=end; ++iter)
	{
		features.vector(*iter,feature_vector);
		matrix.col(iter-begin).array() = feature_vector;
	}

	return matrix;
}

}
}

#endif
