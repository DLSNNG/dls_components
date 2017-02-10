<?php

  module_load_include('inc', 'dls_components', '/includes/components/form/dls_components.input');
  

  class TextField extends Input {

    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'text' => propType::OptionalString(),
        'required' => propType::OptionalBoolean(),
        'label' => propType::OptionalString(),
        'regex' => propType::OptionalString(),
        'regexError' => propType::OptionalString(),
      );
    }
    
    function validateField() {
      $name = $this->props['name'];
      if(!isset($_POST[$name])) { return; } // don't validate unless posted.
      
      $this->getPostValues();
      $this->checkIfRequired();
      $this->applyRegex();
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
    
    function applyRegex() {
      $props = $this->props;
      // skip if no value supplied to input.
      if(trim($props['text']) == '') { return; }
      // skip if no regex supplied to props.
      if(!isset($props['regex'])) { return; } 
      // otherwise compare text with regex
      $name = $props['name'];
      $label = isset($props['label']) ? $props['label'] : $name;
      $text = $props['text'];
      $regex = $props['regex'];
      $error = isset($props['regexError']) ? 
                    $props['regexError'] : 
                    'The field "' . $label . '" should match the format: ' . $regex . '.';
      $matches = preg_match($regex, $text);
      if(!$matches) {
        $this->addError($error);
      }
    }
    
    function render() {
      $props = $this->props;
      $value = isset($props['text']) ? 'value="' . $props['text'] . '"' : '';
      $class = isset($props['class']) ? 'class="' . $props['class'] . '"' : '';
      $block = array(
        '#type' => 'markup',
        '#markup' => '<input type="text" ' . $value . $class . ' name="' . $props['name'] . '">',
      );
      return $block;
    }
  }