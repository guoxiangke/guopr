<?php
/**
 * @file
 * camplus_pr_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function camplus_pr_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_budgets|node|purchase_request|form';
  $field_group->group_name = 'group_budgets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Budget Item',
    'weight' => '3',
    'children' => array(
      0 => 'field_budget_items',
      1 => 'field_budget_items_amount',
    ),
    'format_type' => 'field_group_multiple_table',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'parent_format_type' => 'div',
        'classes' => '',
        'required_fields' => 1,
        'row_titles' => '',
      ),
    ),
  );
  $export['group_budgets|node|purchase_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_budget|node|purchase_request|default';
  $field_group->group_name = 'group_budget';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Budget Info',
    'weight' => '1',
    'children' => array(
      0 => 'field_payment_from_students',
      1 => 'field_budget_items',
      2 => 'field_budget_items_amount',
      3 => 'field_multiple_bi_reason',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_budget|node|purchase_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chosen|node|purchase_request|default';
  $field_group->group_name = 'group_chosen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_supplier';
  $field_group->data = array(
    'label' => 'Chosen Supplier',
    'weight' => '4',
    'children' => array(
      0 => 'field_chosen_price',
      1 => 'field_pr_quotation_file',
      2 => 'field_pr_sole_supplier',
      3 => 'field_chosen_supplier',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Chosen Supplier',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_chosen|node|purchase_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_chosen|node|purchase_request|form';
  $field_group->group_name = 'group_chosen';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Chosen Supplier',
    'weight' => '6',
    'children' => array(
      0 => 'field_chosen_price',
      1 => 'field_chosen_supplier',
      2 => 'field_pr_quotation_file',
    ),
    'format_type' => 'field_group_multiple_container',
    'format_settings' => array(
      'label' => 'Chosen Supplier',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'parent_format_type' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_chosen|node|purchase_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_payment|node|purchase_request|default';
  $field_group->group_name = 'group_payment';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Payment Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_cheque_payable_to',
      1 => 'field_pr_payment_method',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-payment field-group-fieldset ',
      ),
    ),
  );
  $export['group_payment|node|purchase_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_pr_info|node|purchase_request|default';
  $field_group->group_name = 'group_pr_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'PR Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_pr_status',
      1 => 'field_pr_staff',
      2 => 'field_voucher_no',
      3 => 'field_pr_reference',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-pr-info field-group-fieldset ',
      ),
    ),
  );
  $export['group_pr_info|node|purchase_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ref_supplier|node|purchase_request|form';
  $field_group->group_name = 'group_ref_supplier';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Reference Supplier',
    'weight' => '9',
    'children' => array(
      0 => 'field_pr_ref_quotation_file',
      1 => 'field_pr_supplier_contact_no',
      2 => 'field_referenced_price',
      3 => 'field_referenced_supplier',
    ),
    'format_type' => 'field_group_multiple_table',
    'format_settings' => array(
      'label' => 'Reference Supplier',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'parent_format_type' => 'div',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'row_titles' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_ref_supplier|node|purchase_request|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_ref|node|purchase_request|default';
  $field_group->group_name = 'group_ref';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_supplier';
  $field_group->data = array(
    'label' => 'Reference Supplier',
    'weight' => '5',
    'children' => array(
      0 => 'field_referenced_price',
      1 => 'field_pr_ref_quotation_file',
      2 => 'field_referenced_supplier',
      3 => 'field_pr_supplier_contact_no',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
      ),
    ),
  );
  $export['group_ref|node|purchase_request|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_supplier|node|purchase_request|default';
  $field_group->group_name = 'group_supplier';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'purchase_request';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Supplier Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_lower_price_remark',
      1 => 'group_chosen',
      2 => 'group_ref',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Supplier Info',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_supplier|node|purchase_request|default'] = $field_group;

  return $export;
}
