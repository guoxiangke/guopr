<?php
/**
 * @file
 * camplus_pr_feature.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function camplus_pr_feature_taxonomy_default_vocabularies() {
  return array(
    'chosen_suppliers' => array(
      'name' => 'Chosen Suppliers',
      'machine_name' => 'chosen_suppliers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'reference_suppliers' => array(
      'name' => 'Reference Suppliers',
      'machine_name' => 'reference_suppliers',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
