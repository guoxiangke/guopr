<?php
/**
 * @file
 * camplus_pr_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function camplus_pr_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'list_of_users_of_specific_role';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'list of users of specific role';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'list of users of specific role';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer views';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'rid' => 'rid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::user_block_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::flag_user_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Contextual filter: User: Roles */
  $handler->display->display_options['arguments']['rid']['id'] = 'rid';
  $handler->display->display_options['arguments']['rid']['table'] = 'users_roles';
  $handler->display->display_options['arguments']['rid']['field'] = 'rid';
  $handler->display->display_options['arguments']['rid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['rid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['rid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['rid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $export['list_of_users_of_specific_role'] = $view;

  $view = new view();
  $view->name = 'purchase_request_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Purchase Request List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create purchase_request content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'created' => 'created',
    'title' => 'title',
    'field_chosen_supplier' => 'field_chosen_supplier',
    'field_chosen_price' => 'field_chosen_price',
    'field_budget_items' => 'field_budget_items',
    'field_budget_items_amount' => 'field_budget_items_amount',
    'field_payment_from_students' => 'field_payment_from_students',
    'field_parents_department' => 'field_parents_department',
    'field_pr_reference' => 'field_pr_reference',
    'name' => 'name',
    'field_pr_status' => 'field_pr_status',
    'ops' => 'ops',
    'field_voucher_no' => 'field_voucher_no',
    'field_pr_payment_method' => 'field_pr_payment_method',
    'timestamp' => 'timestamp',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_chosen_supplier' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_chosen_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_items' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_items_amount' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_payment_from_students' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_parents_department' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_reference' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'field_voucher_no' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_payment_method' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => '',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_items_target_id']['id'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['field'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['label'] = 'field_budget_items';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_parents_department']['id'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_parents_department']['field'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['fields']['field_parents_department']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Vote results: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last Approval Time';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'Y-m-d';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Last Approval User';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
//dpm($row->nid);
$criteria = array(
    \'entity_type\' => \'node\',
    \'entity_id\' =>$data->nid,
    \'tag\' => \'vote\',
  );
$vo =  votingapi_select_votes($criteria);
//dpm($vo);
if(empty($vo)) return;
$lastvote = end($vo);
$vote_user=user_load($lastvote[\'uid\']);
$link = l($vote_user->name,\'user/\'.$lastvote[\'uid\']);
//dpm($link);
echo $link;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'purchase_request' => 'purchase_request',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = 'between';
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['granularity'] = 'year';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );

  /* Display: My PR */
  $handler = $view->new_display('page', 'My PR', 'page_pr_my');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Purchase Requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'create purchase_request content';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['disable_sql_rewrite'] = TRUE;
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'nid' => 'nid',
    'created' => 'created',
    'title' => 'title',
    'field_chosen_supplier' => 'field_chosen_supplier',
    'field_chosen_price' => 'field_chosen_price',
    'field_budget_items' => 'field_budget_items',
    'field_budget_items_amount' => 'field_budget_items_amount',
    'field_payment_from_students' => 'field_payment_from_students',
    'php_2' => 'php_2',
    'field_pr_status' => 'field_pr_status',
    'php_3' => 'php_3',
    'ops' => 'ops',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_chosen_supplier' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_chosen_price' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_items' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_budget_items_amount' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_payment_from_students' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_pr_status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php_3' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
    'ops' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div><strong><a style="float:right;" href="/node/add/purchase-request">Add Purchase Request</a></strong></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_content';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Flags: cancel */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'cancel';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => '',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'taxonomy_term_reference_link',
  );
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => ' ',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = '';
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php  if($data->field_field_pr_status[0][\'raw\'][\'value\']==1) echo l(\'Submit\',"node/$data->nid/undraft");?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = '';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Vote results: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last Approval Time';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Last Approval';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = 'by [php] - [timestamp]';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$criteria = array(
    \'entity_type\' => \'node\',
    \'entity_id\' =>$data->nid,
    \'tag\' => \'vote\',
  );
$vo =  votingapi_select_votes($criteria);
if(empty($vo)) return;
$vote_user=user_load($vo[0][\'uid\']);
$link = l($vote_user->name,\'user/\'.$vo[0][\'uid\']);
//dpm($link);
echo $link;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'purchase_request' => 'purchase_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: PR Reference # (field_pr_reference) */
  $handler->display->display_options['filters']['field_pr_reference_value']['id'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['filters']['field_pr_reference_value']['field'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_pr_reference_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_reference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['operator_id'] = 'field_pr_reference_value_op';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['label'] = 'PR Reference #';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['operator'] = 'field_pr_reference_value_op';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['identifier'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['path'] = 'pr/my';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'My Purchase Requests';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Purchase Request';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'main-menu';

  /* Display: My Approval record */
  $handler = $view->new_display('page', 'My Approval record', 'approval_record');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Approval Record';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'camplus purchase request approvable';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => '',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_items_target_id']['id'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['field'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['label'] = 'field_budget_items';
  /* Relationship: Content: Votes */
  $handler->display->display_options['relationships']['votingapi_vote']['id'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_vote']['field'] = 'votingapi_vote';
  $handler->display->display_options['relationships']['votingapi_vote']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
  );
  $handler->display->display_options['relationships']['votingapi_vote']['current_user'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_parents_department']['id'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_parents_department']['field'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['fields']['field_parents_department']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Decision';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Vote results: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Last Approval Time';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Last Approval';
  $handler->display->display_options['fields']['php_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php_1']['alter']['text'] = 'by [php_1] - [timestamp]';
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$criteria = array(
    \'entity_type\' => \'node\',
    \'entity_id\' =>$data->nid,
    \'tag\' => \'vote\',
  );
$vo =  votingapi_select_votes($criteria);
if(empty($vo)) return;
$vote_user=user_load($vo[0][\'uid\']);
$link = l($vote_user->name,\'user/\'.$vo[0][\'uid\']);
//dpm($link);
echo $link;
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Votes: User */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'votingapi_vote';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'purchase_request' => 'purchase_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value_1']['id'] = 'field_pr_status_value_1';
  $handler->display->display_options['filters']['field_pr_status_value_1']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value_1']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value_1']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value_1']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Budget Items (field_budget_items:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'pr/my-approval-record';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'My Approval Record';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: My Approval pending */
  $handler = $view->new_display('page', 'My Approval pending', 'pr_approval');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Penind Approval';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'camplus purchase request approvable';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No Purchase Request is pending for your approval!';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => '',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_items_target_id']['id'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['field'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['label'] = 'field_budget_items';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_parents_department']['id'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_parents_department']['field'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['fields']['field_parents_department']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Vote results: Value */
  $handler->display->display_options['fields']['value']['id'] = 'value';
  $handler->display->display_options['fields']['value']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['field'] = 'value';
  $handler->display->display_options['fields']['value']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['value']['label'] = 'Decision';
  $handler->display->display_options['fields']['value']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['value']['precision'] = '0';
  $handler->display->display_options['fields']['value']['separator'] = '';
  $handler->display->display_options['fields']['value']['appearance'] = 'rate_views_widget';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'purchase_request' => 'purchase_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value_1']['id'] = 'field_pr_status_value_1';
  $handler->display->display_options['filters']['field_pr_status_value_1']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value_1']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value_1']['value'] = array(
    3 => '3',
  );
  $handler->display->display_options['filters']['field_pr_status_value_1']['group'] = 1;
  /* Filter criterion: Content: Budget Items (field_budget_items:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'pr/pending-approval';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Pending Approval';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Locked PR */
  $handler = $view->new_display('page', 'Locked PR', 'page_pr_locked');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Locked Purchase Requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view loked purchase request';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Flags: pr_lock */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'pr_lock';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Operation';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'purchase_request' => 'purchase_request',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['value'] = array(
    2 => '2',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['reduce'] = TRUE;
  $handler->display->display_options['path'] = 'pr/locked';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Locked Purchase Requests';
  $handler->display->display_options['menu']['weight'] = '2';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: All PR */
  $handler = $view->new_display('page', 'All PR', 'page_pr_all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All Purchase Requests';
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all purchase request';
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Vote results */
  $handler->display->display_options['relationships']['votingapi_cache']['id'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['table'] = 'node';
  $handler->display->display_options['relationships']['votingapi_cache']['field'] = 'votingapi_cache';
  $handler->display->display_options['relationships']['votingapi_cache']['votingapi'] = array(
    'value_type' => '',
    'tag' => '',
    'function' => '',
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_items_target_id']['id'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['field'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['label'] = 'field_budget_items';
  /* Relationship: Flags: paid */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'paid';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Budget Items */
  $handler->display->display_options['fields']['field_budget_items']['id'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['field'] = 'field_budget_items';
  $handler->display->display_options['fields']['field_budget_items']['label'] = 'From Budget Item';
  $handler->display->display_options['fields']['field_budget_items']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items']['delta_offset'] = '0';
  /* Field: Content: Budget Items Amount */
  $handler->display->display_options['fields']['field_budget_items_amount']['id'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['table'] = 'field_data_field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['field'] = 'field_budget_items_amount';
  $handler->display->display_options['fields']['field_budget_items_amount']['label'] = 'Amount Requested';
  $handler->display->display_options['fields']['field_budget_items_amount']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_budget_items_amount']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  $handler->display->display_options['fields']['field_budget_items_amount']['delta_offset'] = '0';
  /* Field: Content: Payment from Students */
  $handler->display->display_options['fields']['field_payment_from_students']['id'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['table'] = 'field_data_field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['field'] = 'field_payment_from_students';
  $handler->display->display_options['fields']['field_payment_from_students']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_payment_from_students']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_parents_department']['id'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_parents_department']['field'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['fields']['field_parents_department']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag link */
  $handler->display->display_options['fields']['ops']['id'] = 'ops';
  $handler->display->display_options['fields']['ops']['table'] = 'flagging';
  $handler->display->display_options['fields']['ops']['field'] = 'ops';
  $handler->display->display_options['fields']['ops']['relationship'] = 'flag_content_rel';
  $handler->display->display_options['fields']['ops']['label'] = 'Action';
  $handler->display->display_options['fields']['ops']['element_label_colon'] = FALSE;
  /* Field: Content: Voucher # */
  $handler->display->display_options['fields']['field_voucher_no']['id'] = 'field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['table'] = 'field_data_field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['field'] = 'field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_voucher_no']['type'] = 'editable';
  $handler->display->display_options['fields']['field_voucher_no']['settings'] = array(
    'click_to_edit' => 0,
    'empty_text' => '',
    'fallback_format' => 'text_default',
  );
  /* Field: Content: Payment Method */
  $handler->display->display_options['fields']['field_pr_payment_method']['id'] = 'field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['table'] = 'field_data_field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['field'] = 'field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['element_label_colon'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Vote results: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'votingapi_cache';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'Y-m-d';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Last Approval';
  $handler->display->display_options['fields']['php']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['php']['alter']['text'] = 'by [php] - [timestamp]';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$criteria = array(
    \'entity_type\' => \'node\',
    \'entity_id\' =>$data->nid,
    \'tag\' => \'vote\',
  );
$vo =  votingapi_select_votes($criteria);
if(empty($vo)) return;
$vote_user=user_load($vo[0][\'uid\']);
$link = l($vote_user->name,\'user/\'.$vo[0][\'uid\']);
//dpm($link);
echo $link;
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'purchase_request' => 'purchase_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'PR Status (field_pr_status)';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value_1']['id'] = 'field_pr_status_value_1';
  $handler->display->display_options['filters']['field_pr_status_value_1']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value_1']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value_1']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_status_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['operator_id'] = 'field_pr_status_value_1_op';
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['operator'] = 'field_pr_status_value_1_op';
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['identifier'] = 'field_pr_status_value_1';
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['field_pr_status_value_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Department (field_parents_department) */
  $handler->display->display_options['filters']['field_parents_department_target_id']['id'] = 'field_parents_department_target_id';
  $handler->display->display_options['filters']['field_parents_department_target_id']['table'] = 'og_membership';
  $handler->display->display_options['filters']['field_parents_department_target_id']['field'] = 'field_parents_department_target_id';
  $handler->display->display_options['filters']['field_parents_department_target_id']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['filters']['field_parents_department_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_parents_department_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_parents_department_target_id']['expose']['operator_id'] = 'field_parents_department_target_id_op';
  $handler->display->display_options['filters']['field_parents_department_target_id']['expose']['label'] = 'Department';
  $handler->display->display_options['filters']['field_parents_department_target_id']['expose']['operator'] = 'field_parents_department_target_id_op';
  $handler->display->display_options['filters']['field_parents_department_target_id']['expose']['identifier'] = 'field_parents_department_target_id';
  $handler->display->display_options['filters']['field_parents_department_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Payment Method (field_pr_payment_method) */
  $handler->display->display_options['filters']['field_pr_payment_method_value']['id'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['table'] = 'field_data_field_pr_payment_method';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['field'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_payment_method_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['operator_id'] = 'field_pr_payment_method_value_op';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['label'] = 'Payment Method';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['operator'] = 'field_pr_payment_method_value_op';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['identifier'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: PR Reference # (field_pr_reference) */
  $handler->display->display_options['filters']['field_pr_reference_value']['id'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['filters']['field_pr_reference_value']['field'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_pr_reference_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_reference_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['operator_id'] = 'field_pr_reference_value_op';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['label'] = 'PR Reference #';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['operator'] = 'field_pr_reference_value_op';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['identifier'] = 'field_pr_reference_value';
  $handler->display->display_options['filters']['field_pr_reference_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Voucher # (field_voucher_no) */
  $handler->display->display_options['filters']['field_voucher_no_value']['id'] = 'field_voucher_no_value';
  $handler->display->display_options['filters']['field_voucher_no_value']['table'] = 'field_data_field_voucher_no';
  $handler->display->display_options['filters']['field_voucher_no_value']['field'] = 'field_voucher_no_value';
  $handler->display->display_options['filters']['field_voucher_no_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['field_voucher_no_value']['group'] = 1;
  $handler->display->display_options['filters']['field_voucher_no_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_voucher_no_value']['expose']['operator_id'] = 'field_voucher_no_value_op';
  $handler->display->display_options['filters']['field_voucher_no_value']['expose']['label'] = 'Voucher #';
  $handler->display->display_options['filters']['field_voucher_no_value']['expose']['operator'] = 'field_voucher_no_value_op';
  $handler->display->display_options['filters']['field_voucher_no_value']['expose']['identifier'] = 'field_voucher_no_value';
  $handler->display->display_options['filters']['field_voucher_no_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Budget Items (field_budget_items:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['filters']['delta']['group'] = 1;
  $handler->display->display_options['path'] = 'pr/all';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'All Purchase Requests';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view all purchase request';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xls';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'PR_%timestamp-yyyy_%timestamp-mm_%timestamp-dd.xls';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_budget_items_target_id']['id'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['field'] = 'field_budget_items_target_id';
  $handler->display->display_options['relationships']['field_budget_items_target_id']['label'] = 'field_budget_items';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Submitted on';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Item Requested';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Chosen Supplier */
  $handler->display->display_options['fields']['field_chosen_supplier']['id'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['table'] = 'field_data_field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['field'] = 'field_chosen_supplier';
  $handler->display->display_options['fields']['field_chosen_supplier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chosen_supplier']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chosen_supplier']['group_column'] = 'value';
  /* Field: Content: Chosen Price */
  $handler->display->display_options['fields']['field_chosen_price']['id'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['table'] = 'field_data_field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['field'] = 'field_chosen_price';
  $handler->display->display_options['fields']['field_chosen_price']['label'] = 'Price';
  $handler->display->display_options['fields']['field_chosen_price']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 0,
  );
  /* Field: Content: Department */
  $handler->display->display_options['fields']['field_parents_department']['id'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['table'] = 'og_membership';
  $handler->display->display_options['fields']['field_parents_department']['field'] = 'field_parents_department';
  $handler->display->display_options['fields']['field_parents_department']['relationship'] = 'field_budget_items_target_id';
  $handler->display->display_options['fields']['field_parents_department']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_parents_department']['settings'] = array(
    'link' => 0,
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Applicant';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Content: Status */
  $handler->display->display_options['fields']['field_pr_status']['id'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['field'] = 'field_pr_status';
  $handler->display->display_options['fields']['field_pr_status']['element_label_colon'] = FALSE;
  /* Field: Content: Voucher # */
  $handler->display->display_options['fields']['field_voucher_no']['id'] = 'field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['table'] = 'field_data_field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['field'] = 'field_voucher_no';
  $handler->display->display_options['fields']['field_voucher_no']['element_label_colon'] = FALSE;
  /* Field: Content: Payment Method */
  $handler->display->display_options['fields']['field_pr_payment_method']['id'] = 'field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['table'] = 'field_data_field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['field'] = 'field_pr_payment_method';
  $handler->display->display_options['fields']['field_pr_payment_method']['element_label_colon'] = FALSE;
  /* Field: Content: PR Reference # */
  $handler->display->display_options['fields']['field_pr_reference']['id'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['table'] = 'field_data_field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['field'] = 'field_pr_reference';
  $handler->display->display_options['fields']['field_pr_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'purchase_request' => 'purchase_request',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value_1']['id'] = 'field_pr_status_value_1';
  $handler->display->display_options['filters']['field_pr_status_value_1']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value_1']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value_1']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['field_pr_status_value_1']['group'] = 1;
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter']['group'] = 1;
  $handler->display->display_options['filters']['date_filter']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter']['expose']['operator_id'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['date_filter']['expose']['operator'] = 'date_filter_op';
  $handler->display->display_options['filters']['date_filter']['expose']['identifier'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter_1']['group'] = 1;
  $handler->display->display_options['filters']['date_filter_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator_id'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['label'] = 'to';
  $handler->display->display_options['filters']['date_filter_1']['expose']['operator'] = 'date_filter_1_op';
  $handler->display->display_options['filters']['date_filter_1']['expose']['identifier'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_popup';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'node.created' => 'node.created',
  );
  /* Filter criterion: Content: Status (field_pr_status) */
  $handler->display->display_options['filters']['field_pr_status_value']['id'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['table'] = 'field_data_field_pr_status';
  $handler->display->display_options['filters']['field_pr_status_value']['field'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_status_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator_id'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['operator'] = 'field_pr_status_value_op';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['identifier'] = 'field_pr_status_value';
  $handler->display->display_options['filters']['field_pr_status_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Payment Method (field_pr_payment_method) */
  $handler->display->display_options['filters']['field_pr_payment_method_value']['id'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['table'] = 'field_data_field_pr_payment_method';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['field'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pr_payment_method_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['operator_id'] = 'field_pr_payment_method_value_op';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['label'] = 'Payment Method';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['operator'] = 'field_pr_payment_method_value_op';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['identifier'] = 'field_pr_payment_method_value';
  $handler->display->display_options['filters']['field_pr_payment_method_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
    10 => 0,
  );
  /* Filter criterion: Content: Budget Items (field_budget_items:delta) */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_budget_items';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['value']['value'] = '0';
  $handler->display->display_options['path'] = 'pr/export';
  $handler->display->display_options['displays'] = array(
    'page_pr_all' => 'page_pr_all',
    'default' => 0,
    'page_pr_my' => 0,
    'pr_approval' => 0,
    'page_pr_locked' => 0,
  );
  $export['purchase_request_list'] = $view;

  return $export;
}
