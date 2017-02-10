<?php

  module_load_include('inc', 'dls_components', '/includes/components/form/dls_components.input');

  class DateField extends Input {
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'date' => propType::OptionalString(),
        'placeholder' => propType::OptionalString(),
        'format' => propType::OptionalString(),
        'formatError' => propType::OptionalString(),
        'label' => propType::OptionalString(),
        'required' => propType::OptionalBoolean(),
      );
    }
    
    function validateField() {
      $name = $this->props['name'];
      if(!isset($_POST[$name])) { return; } // don't validate unless posted.
      
      $this->getPostValues();
      $this->checkIfRequired();
      $this->validateDate();
    }
    
    function getPostValues() {
      $name = $this->props['name'];
      $this->props['date'] = $_POST[$name];
    }
    
    function checkIfRequired() {
      $props = $this->props;
      $name = $props['name'];
      $label = isset($props['label']) ? $props['label'] : $name;
      $text = $props['date'];
      $required = isset($props['required']) && ($props['required']);
      if($required && trim($text) == '') {
        $this->addError('The field "' . $label . '" is required.');
      }
    }
    
    function validateDate() {
      $props = $this->props;
      // skip if no format supplied
      if(!isset($props['format'])) { return true; }
      // otherwise validate date against format
      $dateString = $props['date'];
      $format = $props['format'];
      $name = $props['name'];
      $label = isset($props['label']) ? $props['label'] : $name;
      $formatError = isset($props['formatError']) ? 
                $props['formatError'] : 
                'The field "' . $label . '" should match the format: ' . $format . '.';
      // allow through if no date supplied
      if($dateString == '') {
        return true;
      }
      // otherwise check date
      $date = DateTime::createFromFormat($format, $dateString);
      // check if valid date was passed in
      if(!$date) {
        $this->addError($formatError);
        return false;
      }
      if(!($date->format($format) == $dateString)) {
        $this->addError($formatError);
        return false;
      }
      else {
        return true;
      }
    }
    
    function render() {
      $props = $this->props;
      $value = isset($props['date']) ? 'value="' . $props['date'] . '"' : '';
      $class = isset($props['class']) ? 'class="' . $props['class'] . '"' : '';
      $placeholder = isset($props['placeholder']) ? 'placeholder="' . $props['placeholder'] . '" ' : '';
      $block = array(
        '#type' => 'markup',
        '#markup' => '<input type="date" ' . $value . $class . $placeholder . ' name="' . $props['name'] . '">',
      );
      return $block;
    }
  }