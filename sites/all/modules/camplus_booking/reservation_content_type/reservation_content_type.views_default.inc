<?php
/**
 * @file
 * reservation_content_type.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function reservation_content_type_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_of_content_types';
  $view->description = '';
  $view->tag = 'booking';
  $view->base_table = 'node';
  $view->human_name = 'List of content types';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Resources category */
  $handler->display->display_options['relationships']['term_node_tid_1']['id'] = 'term_node_tid_1';
  $handler->display->display_options['relationships']['term_node_tid_1']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid_1']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid_1']['ui_name'] = 'Resources category';
  $handler->display->display_options['relationships']['term_node_tid_1']['label'] = 'category';
  $handler->display->display_options['relationships']['term_node_tid_1']['vocabularies'] = array(
    'resource_category' => 'resource_category',
    'reserv_type' => 0,
    'resource_type' => 0,
    'room_floor' => 0,
    'tags' => 0,
  );
  /* Relationship: Resources type */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['ui_name'] = 'Resources type';
  $handler->display->display_options['relationships']['term_node_tid']['label'] = 'type';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'resource_type' => 'resource_type',
    'reserv_type' => 0,
    'resource_category' => 0,
    'room_floor' => 0,
    'tags' => 0,
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Need Approval? */
  $handler->display->display_options['fields']['field_need_approval']['id'] = 'field_need_approval';
  $handler->display->display_options['fields']['field_need_approval']['table'] = 'field_data_field_need_approval';
  $handler->display->display_options['fields']['field_need_approval']['field'] = 'field_need_approval';
  $handler->display->display_options['fields']['field_need_approval']['label'] = '';
  $handler->display->display_options['fields']['field_need_approval']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_need_approval']['alter']['text'] = 'requires Approval by ';
  $handler->display->display_options['fields']['field_need_approval']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_need_approval']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_need_approval']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_need_approval']['type'] = 'list_key';
  /* Field: Content: Approver */
  $handler->display->display_options['fields']['field_approver']['id'] = 'field_approver';
  $handler->display->display_options['fields']['field_approver']['table'] = 'field_data_field_approver';
  $handler->display->display_options['fields']['field_approver']['field'] = 'field_approver';
  $handler->display->display_options['fields']['field_approver']['label'] = '';
  $handler->display->display_options['fields']['field_approver']['element_type'] = 'strong';
  $handler->display->display_options['fields']['field_approver']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_approver']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Floor */
  $handler->display->display_options['fields']['field_resource_category']['id'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['table'] = 'field_data_field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['field'] = 'field_resource_category';
  $handler->display->display_options['fields']['field_resource_category']['label'] = '';
  $handler->display->display_options['fields']['field_resource_category']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_resource_category']['alter']['text'] = '[field_resource_category-tid]';
  $handler->display->display_options['fields']['field_resource_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_category']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Taxonomy term: Name */
  $handler->display->display_options['arguments']['name']['id'] = 'name';
  $handler->display->display_options['arguments']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['name']['field'] = 'name';
  $handler->display->display_options['arguments']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['name']['default_action'] = 'default';
  $handler->display->display_options['arguments']['name']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['name']['default_argument_options']['argument'] = 'Venue';
  $handler->display->display_options['arguments']['name']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['name']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['name']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['name']['limit'] = '0';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_need_approval' => 0,
    'field_approver' => 0,
    'field_resource_category' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $export['list_of_content_types'] = $view;

  return $export;
}
