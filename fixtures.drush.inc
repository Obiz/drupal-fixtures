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
  // Include the menu part of the module.
  fixtures_create_nodes();
  fixtures_create_menus();
  drush_log('Generating menus from YAML files in "sites/all/fixtures"', 'success');
}
