<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class loadingSpinner extends dcomponent {
    function propTypes() {
      return array(
        'message' => propType::String(),
      );
    }
    
    function render() {
      $loadingMessage = array(
        '#type' => 'markup',
        '#markup' => $this->props['message'],
        '#prefix' => '<h3 class="spinner-text">',
        '#suffix' => '</h3>',
      );
      $loadingSpinner = array(
        '#type' => 'markup',
        '#markup' => '',
        '#prefix' => '<div class="spinner">',
        '#suffix' => '</div>',
      );
      $block = array(
        '#type' => 'markup',
        'message' => $loadingMessage,
        'spinner' => $loadingSpinner,
        '#prefix' => '<div class="spinner-overlay"><div class="spinner-wrapper">',
        '#suffix' => '</div></div>',
      );
      
      $block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/loading/dls_components.loadingSpinner.css';
          
      $block['#attached']['js'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/loading/dls_components.loadingSpinner.js';
          
      return $block;
    }
  }