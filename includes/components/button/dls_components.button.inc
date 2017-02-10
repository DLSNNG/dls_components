<?php

  module_load_include('inc', 'dls_components', 'core');
  module_load_include('inc', 'dls_components', '/includes/components/badge/dls_components.badge');
  

  class Button extends dcomponent {
    function propTypes() {
      return array(
        'text' => propType::String(),
        'badge' => propType::OptionalObjectOfType('Badge'),
        'class' => propType::OptionalString(),
        'type' => propType::OptionalString(),
        'url' => propType::OptionalString(),
        'action' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $class = isset($props['class']) ? 
                'class="' . $props['class'] . ' button-wrapper " ' : 
                'class="button-wrapper" ';
      $type = isset($props['type']) ? 'type="' . $props['type'] . '" ' : 'type="button" ';
      // get query params for use with url
      $params = drupal_get_query_parameters();
      // update action if supplied
      if(isset($props['action'])) {
        $params['action'] = $props['action'];
      }
      // use url if supplied. Otherwise pass query params to current path.
      $url = isset($props['url']) ? $props['url'] : current_path();
      $href = 'href="' . url($url, array('query' => $params)) . '" ';
      
      $text = array(
        '#type' => 'markup',
        '#markup' => $props['text'],
      );
      
      $block = array(
        '#type' => 'markup',
        'text' => $text,
        '#prefix' => '<a ' . $class . $href . '><button ' . $type . 'class="button-component">',
        '#suffix' => '</button></a>',
      );
      
      if(isset($props['badge'])) {
          $block['badge'] = $props['badge'];
      }
      
      // add stylesheet for this view
      $path = drupal_get_path('module', 'dls_components');
      
      $block['#attached']['css'] = array(
        $path . '/includes/components/button/dls_components.button.css',
      );
      
      return $block;
    }
  }