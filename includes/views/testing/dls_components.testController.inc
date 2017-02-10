<?php

  module_load_include('inc', 'dls_components', 'core');
  module_load_include('inc', 'dls_components', 'list');
  
  class TestController extends dcontroller {
    
    public $allowedActions = array(
      'test',
    );
    
    protected function onInit() {
      $this->model->props = array(
        'items' => array(
          (object) array('name' => 'nate', 'id' => 1),
          (object) array('name' => 'test', 'id' => 2),
          (object) array('name' => 'tester', 'id' => 3),
        ),
        'adapter' => ListAdapter::make(array(
          'text' => 'name',
        )),
      );
    }
    
    protected function test() {
      $state = $this->model->state;
      $state['added'] = 'added this to state';
      drupal_goto('/epilog', array('query' => $state));
    }
    
  }