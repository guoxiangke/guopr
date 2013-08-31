 jQuery(function($){ 
 	$(document).bind('eventAfterRate', function(event, data)
			{
			  console.log(data);
			  $.ajax({
			      type: 'POST',
			      url: element.href,
			      data: { js: true },
			      dataType: 'json',
			      success: function (data) {
			        if (data.status) {
			          // Success.
			          data.link = $wrapper.get(0);
			          $.event.trigger('flagGlobalBeforeLinkUpdate', [data]);
			          if (!data.preventDefault) { // A handler may cancel updating the link.
			            data.link = updateLink(element, data.newLink);
			          }
			          $.event.trigger('flagGlobalAfterLinkUpdate', [data]);
			        }
			        else {
			          // Failure.
			          alert(data.errorMessage);
			          $wrapper.removeClass('flag-waiting');
			        }
			      },
			      error: function (xmlhttp) {
			        alert('An HTTP error '+ xmlhttp.status +' occurred.\n'+ element.href);
			        $wrapper.removeClass('flag-waiting');
			      }
			    });
			});
	Drupal.behaviors.prRate = {
		attach: function(context, settings) {
			// There are two Javascript hooks available; eventBeforeRate and eventAfterRate.
			// This hook has an argument 'data'. This is an object which contains the variables
			// 'content_type', 'content_id', 'widget_id' and 'widget_mode'. Example of use:

			$(document).bind('eventAfterRate', function(event, data)
			{
			  console.log(data);
			  console.log(data.content_type);
			  console.log(data.widget_mode);
			  console.log(data.widget_id);
			});
		}
	}

});