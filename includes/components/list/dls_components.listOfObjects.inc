<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  module_load_include('inc', 'dls_components', '/includes/components/list/dls_components.listItem');
  

  class listOfObjects extends dcomponent {
    
    function propTypes() {
      return array(
        'items' => propType::Collection(),
        'displayProp' => propType::String(),
        'itemClass' => propType::OptionalString(),
        'listClass' => propType::String(),
      );
    }
    
    function render() {
        $itemClass = isset($this->props['itemClass']) ? $this->props['itemClass'] : 'list-group-item';
    	$list = array(
    	  '#type' => 'markup',
    	  '#prefix' => '<ul class="' . $this->props['listClass'] . '">',
    	  '#suffix' => '</ul>',
    	);
    	$displayProp = $this->props['displayProp'];
    	foreach($this->props['items'] as $item) {
    	  $list[] = listItem::make(array(
    	    'text' => $item->$displayProp,
    	    'class' => $itemClass,
    	  ));
    	}
    	return $list;
    }
  }