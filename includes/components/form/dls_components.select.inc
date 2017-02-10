<?php

  module_load_include('inc', 'dls_components', '/includes/components/form/dls_components.input');

  class Select extends Input {
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'options' => propType::Collection(),
        'selected' => propType::OptionalString(),
        'label' => propType::OptionalString(),
        'required' => propType::OptionalBoolean(),
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
      $this->props['selected'] = $_POST[$name];
    }
    
    function checkIfRequired() {
      $props = $this->props;
      $name = $props['name'];
      $label = isset($props['label']) ? $props['label'] : $name;
      $selected = $props['selected'];
      $required = isset($props['required']) && ($props['required']);
      if($required && trim($selected) == '') {
        $this->addError('The field "' . $label . '" is required.');
      }
    }
    
    function render() {
      $props = $this->props;
      $name = $props['name'];
      $class = isset($props['class']) ? $props['class'] : '';
      $options = $props['options'];
      $selected = isset($props['selected']) ? $props['selected'] : '';
      
      $block = array(
        '#type' => 'markup',
        '#prefix' => '<select name="' . $name . '" class="' . $class . '">',
        '#suffix' => '</select>',
      );
      
      foreach($options as $value => $display) {
        $optionSelected = ($value == $selected) ? 'selected="selected" ' : '';
        $optionValue = ($value == '') ? '' : 'value="' . $value . '" ';
        $block[] = array(
          '#type' => 'markup',
          '#markup' => $display,
          '#prefix' => '<option ' . $optionValue . $optionSelected . '>',
          '#suffix' => '</option>',
        );
      }
      
      return $block;
    }
    
  }