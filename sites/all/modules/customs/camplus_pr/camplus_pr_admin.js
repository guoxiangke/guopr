jQuery(function($){
	$('#edit-camplus-pr-enable-mixable-key').click(function(){

		if(!$('#edit-camplus-pr-enable-mixable-key').is(":checked")) {
			$('#edit-camplus-pr-email-notification-enable').attr('disabled','disabled');
			$('.form-item-camplus-pr-email-notification-addr input').attr("disabled","disabled");
			$('.form-item-camplus-pr-email-notification-addr input').css("background-color","#999");
			$('#edit-camplus-pr-lock-function-enable').attr("disabled","disabled");

		}else{
			$('#edit-camplus-pr-email-notification-enable').removeAttr('disabled');
			$('#edit-camplus-pr-lock-function-enable').removeAttr('disabled');
			if($('#edit-camplus-pr-email-notification-enable').is(":checked")) {
				$('.form-item-camplus-pr-email-notification-addr input').removeAttr('disabled');
				$('.form-item-camplus-pr-email-notification-addr input').css("background-color","");
			}
		}

	});

	$('#edit-camplus-pr-email-notification-enable').click(function(){

		if(!$('#edit-camplus-pr-email-notification-enable').is(":checked")) {
			$('.form-item-camplus-pr-email-notification-addr input').attr("disabled","disabled");
			$('.form-item-camplus-pr-email-notification-addr input').css("background-color","#999");

		}else{
			$('.form-item-camplus-pr-email-notification-addr input').removeAttr('disabled');
			$('.form-item-camplus-pr-email-notification-addr input').css("background-color","");
		}

	});

	if(!$('#edit-camplus-pr-enable-mixable-key').is(":checked")) {
		$('#edit-camplus-pr-email-notification-enable').attr('disabled','disabled');
		$('.form-item-camplus-pr-email-notification-addr input').attr("disabled","disabled");
		$('.form-item-camplus-pr-email-notification-addr input').css("background-color","#999");
		$('#edit-camplus-pr-lock-function-enable').attr("disabled","disabled");
	}

	if(!$('#edit-camplus-pr-email-notification-enable').is(":checked")) {
			$('.form-item-camplus-pr-email-notification-addr input').attr("disabled","disabled");
			$('.form-item-camplus-pr-email-notification-addr input').css("background-color","#999");

		}

});
