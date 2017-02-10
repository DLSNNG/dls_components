<?php

  module_load_include('inc', 'dls_components', '/includes/components/form/dls_components.input');
  

  class TextArea extends Input {

    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'text' => propType::OptionalString(),
        'required' => propType::OptionalBoolean(),
        'label' => propType::OptionalString(),
      );
    }
    
    function validateField() {
      $name = $this->props['name'];
      if(!isset($_POST[$name])) { return; } // don't validate unless posted.
      
      $this->getPostValues();
      $this->checkIfRequired();
    }
    
    function getPostValues() {
      $name = $this->props['name'];
      $this->props['text'] = $_POST[$name];
    }
    
    function checkIfRequired() {
      $props = $this->props;
      $name = $props['name'];
      $label = isset($props['label']) ? $props['label'] : $name;
      $text = $props['text'];
      $required = isset($props['required']) && ($props['required']);
      if($required && trim($text) == '') {
        $this->addError('The field "' . $label . '" is required.');
      }
    }
    
    function render() {
      $props = $this->props;
      $value = isset($props['text']) ? $props['text'] : '';
      $class = isset($props['class']) ? 'class="' . $props['class'] . '"' : '';
      $block = array(
        '#type' => 'markup',
        '#markup' => $value,
        '#prefix' => '<textarea ' . $class . ' name="' . $props['name'] . '">',
        '#suffix' => '</textarea>',
      );
      return $block;
    }
  }