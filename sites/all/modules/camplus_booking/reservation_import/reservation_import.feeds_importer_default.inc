<?php
/**
 * @file
 * reservation_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function reservation_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_resources';
  $feeds_importer->config = array(
    'name' => 'Import Resources',
    'description' => 'Import school resources like room and equipment',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'resource_name',
            'target' => 'title',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'quantity',
            'target' => 'field_quantity',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'approval',
            'target' => 'field_need_approval',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'approver',
            'target' => 'field_approver:label',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'resource_type',
            'target' => 'field_resource_type',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'floor',
            'target' => 'field_resource_category',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'resource',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_resources'] = $feeds_importer;

  return $export;
}
