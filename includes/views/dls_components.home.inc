<?php

  module_load_include('inc', 'dls_components', '/includes/components/list/dls_components.linkListOfObjects');
  module_load_include('inc', 'dls_components', '/includes/components/element');
  module_load_include('inc', 'dls_components', '/includes/components/orbital/dls_components.orbital');
  module_load_include('inc', 'dls_components', '/includes/components/loading/dls_components.loadingSpinner');
  module_load_include('inc', 'dls_components', '/includes/components/icon/dls_components.font_awesome_icon');
  module_load_include('inc', 'dls_components', 'form');
  module_load_include('inc', 'dls_components', 'button');
  module_load_include('inc', 'dls_components', 'core');
  module_load_include('inc', 'dls_components', '/includes/views/testing/dls_components.testController');
  
  function view_dls_components_home() {
    /*
    $people = array(
      (object) array('name' => 'nate', 'id' => 1),
      (object) array('name' => 'test', 'id' => 2),
      (object) array('name' => 'tester', 'id' => 3),
    );
    $block = array(
      '#type' => 'markup',
      'title' => element::make(array(
        'type' => 'h3',
        'text' => 'People',
        'class' => 'big-header',
      )),
      'list' => linkListOfObjects::make(array(
        'items' => $people,
        'displayProp' => 'name',
        'listClass' => 'list-group',
        'itemClass' => 'item',
        'url' => current_path(),
        'linkProp' => 'id',
      )),
    );
    
    $pagination = array(
      '#type' => 'markup',
      '#markup' => 'testing',
      '#prefix' => '<div class="pagination"><a>',
      '#suffix' => '</a></div>',
    );
    */
    
    //testing
    $params = drupal_get_query_parameters();
    $block = array(
      '#type' => 'markup',
      //'pagination' => $pagination,
      'form' => Form::make(array(
        'class' => 'testing',
        'fields' => array(
          TextField::make(array(
            'name' => 'testing1',
            'class' => 'red',
            'label' => 'My labeled input',
            'required' => true,
            'regex' => '/^(\d{5})$/',
            'regexError' => 'The field "My labeled input" should be 5 numbers.',
            'text' => isset($params['testing1']) ? $params['testing1'] : '',
          )),
          TextField::make(array(
            'name' => 'testing2',
            'class' => 'blue',
            'label' => 'Another label',
            'text' => isset($params['testing2']) ? $params['testing2'] : '',
          )),
          DateField::make(array(
            'name' => 'date',
            'class' => 'green',
            'label' => 'Select a Date',
            'required' => true,
            'format' => 'Y-m-d',
            'formatError' => 'The field "Select a date" should follow the format YYYY-mm-dd.',
            'date' => isset($params['date']) ? $params['date'] : '',
          )),
          Select::make(array(
            'name' => 'select',
            'label' => 'Select one of these',
            'class' => 'orange',
            'required' => 'true',
            'options' => array(
              ' ' => '--Select--',
              'test1' => 'test',
              'test2' => 'test2',
              'test3' => 'test3',
            ),
            'selected' => isset($params['select']) ? $params['select'] : array(),
          )),
          SelectMultiple::make(array(
            'name' => 'selectmultiple',
            'label' => 'Select one (or more) of these',
            'class' => 'purple',
            'required' => 'true',
            'options' => array(
              'test1' => 'test',
              'test2' => 'test2',
              'test3' => 'test3',
            ),
            'selected' => isset($params['selectmultiple']) ? $params['selectmultiple'] : array(),
          )),
          Checkbox::make(array(
            'name' => 'check',
            'label' => 'Check this',
            'class' => 'yellow',
            'checked' => isset($params['check']),
          )),
          TextArea::make(array(
            'name' => 'textarea1',
            'class' => 'blue',
            'label' => 'Text Area',
            'text' => isset($params['textarea1']) ? $params['textarea1'] : '',
            'required' => true,
          )),
          Submit::make(array(
            'value' => 'submit',
            'text' => 'Submit',
          )),
          Submit::make(array(
            'value' => 'cancel',
            'text' => 'Cancel',
          )),
          dpage::make('ListView', 'TestController'),
        ),
      )),
      /*
      'orbital' => Orbital::make(array(
        'size' => '250px',
        'class' => '',
        'items' => array(
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-bed',
            'className' => 'pt-icon small',
          )),
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-flask',
            'className' => 'samples-icon bg-green small',
          )),
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-laptop',
            'className' => 'orders-icon bg-purple small',
          )),
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-user-md',
            'className' => 'client-icon bg-orange small',
          )),
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-hospital-o',
            'className' => 'hospital-icon bg-red small',
          )),
          FontAwesomeIcon::make(array(
            'iconType' => 'fa-usd',
            'className' => 'billing-icon bg-yellow small',
          )),
        ),
      )),
      */
      'spinner' => loadingSpinner::make(array(
          'message' => 'Loading Spinner...',
       )),
    );
    
    // TODO: use MVC + Component pattern to build alternate inquiry page
    //$block = dpage::make('ListView', 'TestController');
    
    return $block;
  }