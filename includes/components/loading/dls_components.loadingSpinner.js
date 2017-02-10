/* global jQuery */

(function($){
  $(document).on('submit', 'form', function() {
    $('.spinner-overlay').addClass('active');
  });
  
  $(document).on('click', '.pagination a', function() {
    $('.spinner-overlay').addClass('active');
  });
}(jQuery));