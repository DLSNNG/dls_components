<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  module_load_include('inc', 'dls_components', '/includes/components/list/dls_components.listItem');
  

  class unorderedList extends dcomponent {
    function propTypes() {
      return array(
        'items' => propType::Collection(),
        'itemClass' => propType::OptionalString(),
        'listClass' => propType::OptionalString(),
        'activeIndex' => propType::OptionalNumber(),
      );
    }
    
    function render() {
      $itemClass = isset($this->props['itemClass']) ? $this->props['itemClass'] : 'list-group-item';
      $listClass = isset($this->props['listClass']) ? $this->props['listClass'] : 'list-group';
      $active = isset($this->props['activeIndex']) ? $this->props['activeIndex'] : -1;
    	$list = array(
    	  '#type' => 'markup',
    	  '#prefix' => '<ul class="' . $listClass . '">',
    	  '#suffix' => '</ul>',
    	);
    	foreach($this->props['items'] as $key => $item) {
    	  $activeItemClass = ($key === $active) ? $itemClass . ' active' : $itemClass;
    	  $list[] = listItem::make(array(
    	    'text' => $item,
    	    'class' => $activeItemClass,
    	  ));
    	}
    	
    	$list['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/list/dls_components.list.css';
    	return $list;
    }
  }