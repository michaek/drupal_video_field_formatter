<?php

$plugin = array(
  'provider' => 'LimelightVideoProvider',
);

class LimelightVideoProvider {
  
  public function process_url(&$url, &$settings) {
    $parts = drupal_parse_url($url);
    extract(drupal_parse_url($url));

    // TODO: determine a real way to identify this provider.
    if (strpos($path, 'llnwd.net')) {
      // TODO: provide a setting for streamer URI.
      $settings['streamer'] = 'rtmpt://streamer.exaple.com/';
    }
  }
  
}
