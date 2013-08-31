<?php
/**
 * @file
 * import_users.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function import_users_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_users';
  $feeds_importer->config = array(
    'name' => 'Import Users',
    'description' => '',
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
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          4 => 0,
          5 => 0,
          6 => 0,
          7 => 0,
          8 => 0,
          9 => 0,
          3 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'username',
            'target' => 'name',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'email',
            'target' => 'mail',
            'unique' => 0,
          ),
          2 => array(
            'source' => 'name',
            'target' => 'field_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'role',
            'target' => 'roles_list',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'password',
            'target' => 'pass',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '2',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_users'] = $feeds_importer;

  return $export;
}
