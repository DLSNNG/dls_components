<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class Label extends dcomponent {
    function propTypes() {
      return array(
        'for' => propType::String(),
        'text' => propType::String(),
        'class' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $text = $props['text'];
      $for = 'for="' . $props['for'] . '" ';
      $class = isset($props['class']) ? 'class="' . $props['class'] . '"' : '';
      $block = array(
        '#type' => 'markup',
        '#markup' => $text,
        '#prefix' => '<label ' . $for . $class . '>',
        '#suffix' => '</label>',
      );
      return $block;
    }
  }