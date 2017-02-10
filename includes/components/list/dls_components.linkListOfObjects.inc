<?php

  module_load_include('inc', 'dls_components', '/includes/library/dls_components.dcomponent');
  module_load_include('inc', 'dls_components', '/includes/components/list/dls_components.linkListItem');
  

  class linkListOfObjects extends dcomponent {
    
    function propTypes() {
      return array(
        'items' => propType::Collection(),
        'displayProp' => propType::String(),
        'itemClass' => propType::OptionalString(),
        'listClass' => propType::String(),
        'url' => propType::String(),
        'linkProp' => propType::String(),
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
    	  $params = $this->updateQueryParams($item);
    	  $url = url($this->props['url'], array('query'=> $params));
    	  $list[] = linkListItem::make(array(
    	    'text' => $item->$displayProp,
    	    'class' => $itemClass,
    	    'url' => $url,
    	  ));
    	}
    	return $list;
    }
    
    function updateQueryParams($item) {
      $params = drupal_get_query_parameters();
      $linkProp = $this->props['linkProp'];
      $params[$linkProp] = $item->$linkProp;
      return $params;
    }
  }