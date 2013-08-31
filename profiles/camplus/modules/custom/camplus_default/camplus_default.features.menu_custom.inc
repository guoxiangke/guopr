<?php
/**
 * @file
 * camplus_default.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function camplus_default_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Main menu',
    'description' => 'The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-sch-admin.
  $menus['menu-sch-admin'] = array(
    'menu_name' => 'menu-sch-admin',
    'title' => 'School Administration',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Main menu');
  t('School Administration');
  t('The <em>Main</em> menu is used on many sites to show the major sections of the site, often in a top navigation bar.');


  return $menus;
}
