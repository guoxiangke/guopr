<?php
/**
 * @file
 * reservation_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function reservation_content_type_taxonomy_default_vocabularies() {
  return array(
    'booking_type' => array(
      'name' => 'Booking Type',
      'machine_name' => 'booking_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'resource_category' => array(
      'name' => 'Floor',
      'machine_name' => 'resource_category',
      'description' => 'e.g. 1/F, 2/F, Lab',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'resource_type' => array(
      'name' => 'Resource Type',
      'machine_name' => 'resource_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 1,
    ),
  );
}
