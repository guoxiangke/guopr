(function ($) {
  Drupal.behaviors.timeslot = {
    attach: function(context, settings) {
      // alert('a');
      $('form', context).once('timeslot-process', function(){

        // rearrange fields
        $('.form-item-field-date-und-0-value2-time').insertAfter('.form-item-field-date-und-0-value-time');
        $('.form-item-field-date-und-0-value-time label').html('From Time');
        $('.form-item-field-date-und-0-value2-time label').html('To Time');
        $('.end-date-wrapper').hide();
        $('.form-item-field-date-und-0-value-time').hide();
        $('.form-item-field-date-und-0-value2-time').hide();

        // prepare exisiting values
        var start_time = $('.form-item-field-date-und-0-value-time input').val();
        var end_time = $('.form-item-field-date-und-0-value2-time input').val();

        // populate select
        options = '';
        var selected = false;
        var start_matching = false; // checking if timeslots fits exisiting value
        for(i in Drupal.settings.timeslot.values) {
          if(Drupal.settings.timeslot.values[i].substr(0,5) == start_time) {
            selected = true;
            start_matching = true;
          }
          if(selected) {
            options += '<option selected="selected" value="'+Drupal.settings.timeslot.values[i]+'">'+Drupal.settings.timeslot.names[i]+'</option>';
          } else {
            options += '<option value="'+Drupal.settings.timeslot.values[i]+'">'+Drupal.settings.timeslot.names[i]+'</option>';
          }
          if(Drupal.settings.timeslot.values[i].substr(6,5) == end_time) {
            selected = false;
          }
        }

        $('#edit-field-date-und-0-value .form-item-field-date-und-0-value-date:not(.processed)').addClass('processed').after('<div class="form-item" id="multiselect-wrapper">'+
          '<label for="timeslot">Time <a href="#" class="timelsot-advance">Advance</a></label>'+
          '<span class="timeEntry_wrap">'+
          '<select id="timeslot" multiple="multiple">'+
          // '<option value="">Select</option>'+
          // '<option value="0000-0200">00:00 - 02:00</option>'+
          options+
          '</select>'+
          '</span></div>');

        $('#multiselect-wrapper label a').click(function(){
          $('#multiselect-wrapper').hide();
          $('.form-item-field-date-und-0-value-time').slideDown();
          $('.form-item-field-date-und-0-value2-time').slideDown();
          return false;
        });

        $('#edit-field-date-und-0-value-datepicker-popup-0').change(function(){
          $('#edit-field-date-und-0-value2-datepicker-popup-0').val($('#edit-field-date-und-0-value-datepicker-popup-0').val());
        });

        // $('.form-item-field-date-und-0-value2-time label a').click(function(){
        //   $('#multiselect-wrapper').slideDown();
        //   $('.form-item-field-date-und-0-value-time').hide();
        //   $('.form-item-field-date-und-0-value2-time').hide();
        //   return false;
        // });

        $('#timeslot').multiselect({
          header: false,
          noneSelectedText: "Select timeslots",
          header:false,
          selectedList: 0,
          uncheckAll: function(event, ui) {
            $(this).multiselect("widget").find("input:checked").attr({'checked':false});
          },
          click: function(e){
            checked_count = $(this).multiselect("widget").find("input:checked:not(:disabled)").length;
            
            if( checked_count > 2 ){
              //connect more checkboxes, max only 3 not disabled checkbox

              var start       = $(this).multiselect("widget").find("input:checked:not(:disabled)").eq(0);
              var start_index = parseInt($(start).attr('id').substr('31'));
              var start_value = $(start).val().substr(0,5);
              var end         = $(this).multiselect("widget").find("input:checked:not(:disabled)").eq(2);
              var end_index   = parseInt($(end).attr('id').substr('31'));
              var end_value   = $(end).val().substr(6,5);
              for( i=start_index+1 ; i<end_index ; i++ ) {
                $(this).multiselect("widget").find("input").eq(i).attr({'disabled':'disabled', 'checked':true});
              }

              $('.form-item-field-date-und-0-value-time input').val(start_value).change();
              $('.form-item-field-date-und-0-value2-time input').val(end_value).change();
              
            } else if ( checked_count == 2 ){
              
              //connect between two checkboxes
              var start       = $(this).multiselect("widget").find("input:checked:not(:disabled)").eq(0);
              var start_index = parseInt($(start).attr('id').substr('31'));
              var start_value = $(start).val().substr(0,5);
              var end         = $(this).multiselect("widget").find("input:checked:not(:disabled)").eq(1);
              var end_index   = parseInt($(end).attr('id').substr('31'));
              var end_value   = $(end).val().substr(6,5);
              for( i=start_index+1 ; i<end_index ; i++ ) {
                $(this).multiselect("widget").find("input").eq(i).attr({'disabled':'disabled', 'checked':true});
              }

              $('.form-item-field-date-und-0-value-time input').val(start_value).change();
              $('.form-item-field-date-und-0-value2-time input').val(end_value).change();
              
            } else if ( checked_count == 1 ){
              //handle fall from 2 to 1 checkbox, enable disabled checkboxes
              $(this).multiselect("widget").find("input:checked:disabled").removeAttr('disabled').removeAttr('checked');

              var start       = $(this).multiselect("widget").find("input:checked:not(:disabled)").eq(0);
              var start_value = $(start).val().substr(0,5);
              var end_value   = $(start).val().substr(6,5);
              $('.form-item-field-date-und-0-value-time input').val(start_value).change();
              $('.form-item-field-date-und-0-value2-time input').val(end_value).change();

            }
          }
        });

        // $('.timelsot-advance').click();
        
      });
    }
  }
})(jQuery);