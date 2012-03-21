<?php 

/**
 * Implements hook_ctools_plugin_api().
 */
function video_field_formatter_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == 'video_field_formatter' && $api == 'video_provider') {
    return array("version" => "1");
  }
}

function video_field_formatter_ctools_plugin_directory($owner, $plugin_type) {
  if ($owner == 'video_field_formatter') {
    return "plugins/$plugin_type";
  }
}

function video_field_formatter_ctools_plugin_type() {
  return array(
    'video_provider' => array(
      'cache' => TRUE,
      'use hooks' => TRUE,
      'classes' => array(),
    ),
  );
}

function video_field_formatter_get_provider($provider) {
  ctools_include('plugins');
  return ctools_get_plugins('video_field_formatter', 'video_provider', $provider);
}

function video_field_formatter_get_providers() {
  ctools_include('plugins');
  return ctools_get_plugins('video_field_formatter', 'video_provider');
}

function video_field_formatter_get_provider_handlers() {
  $providers = video_field_formatter_get_providers();
  $handlers = array();
  foreach ($providers as $plugin) {
    $class = ctools_plugin_get_class($plugin, 'provider');
    if ($class) {
      $handlers[$plugin['name']] = new $class();
    }
  }
  return $handlers;
}
