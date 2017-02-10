<?php

  module_load_include('inc', 'dls_components', 'core');
  

  class Badge extends dcomponent {
    function propTypes() {
      return array(
        'text' => propType::String(),
        'class' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $class = isset($props['class']) ? 'class="badge ' . $props['class'] . '" ' : 'class="badge" ';
      
      $block = array(
        '#type' => 'markup',
        '#markup' => $props['text'],
        '#prefix' => '<span ' . $class . '>',
        '#suffix' => '</span>',
      );
      
      // add stylesheet for this view
      $path = drupal_get_path('module', 'dls_components');
      
      $block['#attached']['css'] = array(
        $path . '/includes/components/badge/dls_components.badge.css',
      );
      
      return $block;
    }
  }