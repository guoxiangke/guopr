<?php
/**
 * @file
 * default_clean_theme.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function default_clean_theme_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'textsize_block_type';
  $strongarm->value = 'image';
  $export['textsize_block_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'textsize_display_current_inline';
  $strongarm->value = 1;
  $export['textsize_display_current_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'textsize_display_current_text_value';
  $strongarm->value = 'hidden';
  $export['textsize_display_current_text_value'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'textsize_display_list_inline';
  $strongarm->value = 1;
  $export['textsize_display_list_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_clean_theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => '',
    'favicon_upload' => '',
    'breadcrumbs' => 0,
    'slideshow_display' => 0,
    'slide1_head' => 'This is Slide Headline',
    'slide1_desc' => 'Lorem ipsum dolor  eiusmod sit amet, consectetur adipisicing elit, sed do eiusmod tempor',
    'slide2_head' => 'Custom Heading',
    'slide2_desc' => 'Lorem ipsum dolor amet, consectetur incididunt ut  adipisicing elit, sed do eiusmod tempor',
    'slide3_head' => 'Slide Headline',
    'slide3_desc' => 'adipisicing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua',
  );
  $export['theme_clean_theme_settings'] = $strongarm;

  return $export;
}
