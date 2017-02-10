<?php

  module_load_include('inc', 'dls_components', 'core');
  
  class ListView extends dcomponent {
    
    function propTypes() {
      return array(
        'items' => propType::Collection(),
        'adapter' => propType::ObjectOfType('ListAdapter'),
        'itemComponentName' => propType::OptionalString(),
        'listClass' => propType::OptionalString(),
        'activeIndex' => propType::OptionalNumber(),
      );
    }
    
    function render() {
      $props = $this->props;
      $adapter = $props['adapter'];
      $itemComponent = isset($props['itemComponentName']) ? $props['itemComponentName'] : 'listItem';
      $itemClass = isset($props['itemClass']) ? $props['itemClass'] : 'list-group-item';
      $listClass = isset($props['listClass']) ? $props['listClass'] : 'list-group';
      $active = isset($props['activeIndex']) ? $props['activeIndex'] : -1;
    	$list = array(
    	  '#type' => 'markup',
    	  '#prefix' => '<ul class="' . $listClass . '">',
    	  '#suffix' => '</ul>',
    	);
    	foreach($this->props['items'] as $key => $item) {
    	  $listItemProps = $adapter->map($item);
    	  if($key === $active) {
    	    $listItemProps['class'] = 'active ' . $listItemProps['class'];
    	  }
    	  $list[] = $itemComponent::make($listItemProps);
    	}
    	
    	$list['#attached']['css'][] = drupal_get_path('module', 'dls_components')
          . '/includes/components/list/dls_components.list.css';
    	return $list;
    }
  }