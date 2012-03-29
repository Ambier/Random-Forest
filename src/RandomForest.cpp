/*
 * RandomForest.cpp
 *
 *  Created on: Mar 29, 2012
 *      Author: anthony
 */

#include "RandomForest.h"

//------------------------------------------------------------------------------

void RandomForest::grow_forest(
  Dataset & dataset,
  const unsigned int decision_column,
  const unsigned int bootstrap_size,
  const Dataset::KeyList & split_keys,
  const unsigned int keys_per_node,
  const unsigned int tree_count )
{
  // If a forest exits, destroy it.
  burn();

  // Iteratively build each tree.
  for ( unsigned int tree_index = 0; tree_index < tree_count; ++tree_index )
  {
    // Generate a bootstrap sample.
    Dataset bootstrap = dataset.bootstrap_sample(bootstrap_size);

    // Generate the random tree.
    forest.push_back( RandomTree() );
    forest[tree_index].grow_decision_tree(
      bootstrap, split_keys, keys_per_node, decision_column );
  }
}

//------------------------------------------------------------------------------

bool RandomForest::classify( const double * const & row )
{
  return false;
}

//------------------------------------------------------------------------------

void RandomForest::classify_oob( const Dataset::KeyList & keys_to_permute )
{
  //
}

//------------------------------------------------------------------------------
