<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  

  class Input extends dcomponent {
    
    var $hasFormErrors = false;  
    
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'name' => propType::String(),
        'label' => propType::OptionalString(),
      );
    }
    
    // Override DComponent _render() method to insert _onPost handler
    function _render() {
      //if we have prop errors, show the errors
      if(count($this->errors) > 0) {
        return $this->renderErrors();
      }
      //otherwise render the component
      else {
        // handle post values.
        $this->_onValidateField();
        // render component.
        $block = $this->render();
        $block = $this->addLabel($block);
        return $block;
      }
    }
    
    function _onValidateField() {
      // exit here if canceling form.
      if(isset($_POST['action']) && $_POST['action'] == 'cancel') { return; }
      // otherwise do validation
      $this->validateField();
      $this->_highlightErrors();
    }
    
    function addError($message) {
      $this->hasFormErrors = true;
      form_set_error($this->props['name'], $message);
    }
    
    function _highlightErrors() {
      if($this->hasFormErrors) {
        $props = $this->props;
        $this->props['class'] = isset($props['class']) ? ' form-error ' . $props['class'] : 'form-error ';
      }
    }
    
    // implemented in child class
    function validateField() {}
    
    function addLabel($block) {
      $props = $this->props;
      if(isset($props['label'])) {
        $for = 'for="' . $props['name'] . '" ';
        $labelClass = isset($props['class']) ? 'class="label ' . $props['class'] . '"' : '';
        $wrapperClass = isset($props['class']) ? 'class="' . $props['class'] . '-wrapper form-item" ' : '';
        $label = array(
          '#type' => 'markup',
          '#markup' => $props['label'],
          '#prefix' => '<label ' . $for . $labelClass . '>',
          '#suffix' => '</label>',
        );
        
        $labeledBlock = array(
          '#type' => 'markup',
          '#prefix' => '<div ' . $wrapperClass . '>',
          '#suffix' => '</div>',
        );
        
        $labeledBlock[] = $label;
        $labeledBlock[] = $block;
        
        $block = $labeledBlock;
      }
      return $block;
    }
    
    // implemented in child class
    function render() {}
  }