<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');

  class Form extends dcomponent {
    
    var $postValues = array();
    
    function propTypes() {
      return array(
        'class' => propType::OptionalString(),
        'fields' => propType::Collection(),
        'target' => propType::OptionalString(),
      );
    }
    
    // Override DComponent _render() method to insert _onPost handler
    function _render() {
      //if we have errors, show the errors
      if(count($this->errors) > 0) {
        return $this->renderErrors();
      }
      //otherwise render the component
      else {
        // handle post values.
        $this->_onPost();
        // render component.
        return $this->render();
      }
    }
    
    // core Form handling. Do not override
    function _onPost() {
      // if action is cancel, call onCancel()
      if(isset($_POST['action']) && $_POST['action'] == 'cancel') {
        $this->onCancel();
        return;
      }
      // otherwise check for errors
      if(form_get_errors()) { return; } // don't do anything if there are errors
      // grab post data if everything looks good
      $this->postValues = $this->_getPostValues();
      if(count($this->postValues) > 0) {
        $this->onPost();
      }
    }
    
    // core Form handling. Do not override
    function _getPostValues() {
      $params = $_POST;
      // remove any blank post values
      foreach($params as $key => $value) {
        if(trim($value) == '') {
          unset($params[$key]);
        }
      }
      return $params;
    }
    
    // default behavior. Override to change post handling.
    function onPost() {
      // save post data to query params
      $target = isset($props['target']) ? $props['target'] : url(current_path(), array('absolute' => TRUE));
      
      drupal_goto($target, array('query' => $this->postValues));
    }
    // default behavior. Override to change post handling.
    function onCancel() {
      // refresh page
      $target = isset($props['target']) ? $props['target'] : url(current_path(), array('absolute' => TRUE));
      drupal_goto($target, array());
    }
    
    function render() {
      $props = $this->props;
      $class = isset($props['class']) ? 'class="' .$props['class'] . '" ' : '';
      $params = drupal_get_query_parameters();
      $target = url(current_path(), array('absolute' => TRUE, 'query' => $params)); //need to hit onPost handler first.

    	$block = array(
    	  '#type' => 'markup',
    	  '#prefix' => '<form action="' . $target . '" method="post" ' . $class . '>',
    	  '#suffix' => '</form>',
    	);
    	foreach($props['fields'] as $field) {
    	  $block[] = $field;
    	}
    	
    	// add css
    	$block['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/form/dls_components.form.css';
    	
    	return $block;
    }
    
  }