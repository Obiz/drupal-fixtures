<?php
function fixtures_drush_command() {
  $items = array();
  // Run all fixtures of all types
  $items['fixtures-all'] = array(
    'description' => 'Run all of the fixtures',
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'callback' => 'fixtures_drush_create_all',
  );
  return $items;
}

function fixtures_drush_create_all() {
  // Import users
  fixtures_create_users();
  drush_log('Generated users from YAML files in "sites/all/fixtures"', 'success');
  // Import nodes
  fixtures_create_nodes();
  drush_log('Generated nodes from YAML files in "sites/all/fixtures"', 'success');
  // Import menu items
  fixtures_create_menus();
  drush_log('Generated menus from YAML files in "sites/all/fixtures"', 'success');
}
