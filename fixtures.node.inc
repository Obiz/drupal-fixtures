<?php

/**
 * Create all nodes
 */
function fixtures_create_nodes() {
  $fixtures = fixtures_get_fixtures('node');
  foreach ($fixtures as $fixture) {
    foreach ($fixture as $node_name => $node_array) {
      $node = fixture_create_node($node_array);
    }
  }
  return "debugging fixtures";
}

/**`
 * Create single node from YAML array
 */
function fixture_create_node($node_array) {
  $node = new stdClass();
  $node->type = $node_array['type'];
  //node_object_prepare($node);
  $node->title = $node_array['title'];
  $node->body['und'][0]['value'] = $node_array['body'];
  $node->body['und'][0]['format'] = 'full_html';
  $node->created = strtotime($node_array['date']);
  $node->changed = $node->created;
  $node->language = 'en';
  $node->path = array('alias' => $node_array['path'] ) ;
  node_save($node);
  return $node;
}
