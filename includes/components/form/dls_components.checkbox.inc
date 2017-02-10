<?php

  module_load_include('inc', 'dls_components', '/includes/components/form/dls_components.input');
  

  class Checkbox extends Input {
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'checked' => propType::OptionalBoolean(),
        'label' => propType::OptionalString(),
      );
    }
    
    function validateField() {
      $props = $this->props;
      $name = $props['name'];
      if(isset($_POST[$name])) {
        $this->props['checked'] = $_POST[$name];
      }
    }
    
    function addLabel($block) {
      $props = $this->props;
      if(isset($props['label'])) {
        $labelClass = isset($props['class']) ? 'class="' . $props['class'] . '-label"' : '';
        $label = array(
          '#type' => 'markup',
          '#markup' => $props['label'],
        );
        
        $labeledBlock = array(
          '#type' => 'markup',
          '#prefix' => '<label ' . $labelClass . '>',
          '#suffix' => '</label>',
        );
        
        $labeledBlock[] = $block;
        $labeledBlock[] = $label;
        
        
        $block = $labeledBlock;
      }
      return $block;
    }
    
    function render() {
      $props = $this->props;
      $name = $props['name'];
      if(!isset($props['checked'])) {
        $checked = '';
      }
      else {
        $checked = $props['checked'] ? 'checked="checked"' : '';
      }
      $class = isset($props['class']) ? 'class="' . $props['class'] . '"' : '';
      $block = array(
        '#type' => 'markup',
        '#markup' => '<input type="checkbox" ' . $checked . $class . ' name="' . $name . '" value="1">',
      );
      return $block;
    }
  }