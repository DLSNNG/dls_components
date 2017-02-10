<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class Submit extends dcomponent {
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'text' => propType::OptionalString(),
        'name' => propType::OptionalString(),
        'value' => propType::OptionalString(),
      );
    }
    
    function render() {
      $props = $this->props;
      $name = isset($props['name']) ? 'name="' . $props['name'] . '" ' : 'name="action" ';
      $value = isset($props['value']) ? 'value="' . $props['value'] . '" ' : 'value="submit" ';
      $text = isset($props['text']) ? $props['text'] : 'Submit';
      $class = isset($props['class']) ? 
                'class="' . $props['class'] . '" ' : 
                '';
      $wrapperClass = isset($props['class']) ? 
                'class="form-item ' . $props['class'] . '-wrapper" ' : 
                'class="form-item" ';
      
      $block = array(
        '#type' => 'markup',
        '#markup' => $text,
        '#prefix' => '<div ' . $wrapperClass . '><button type="submit"' . $name . $value . $class . '>',
        '#suffix' => '</button></div>',
      );
      return $block;
    }
  }