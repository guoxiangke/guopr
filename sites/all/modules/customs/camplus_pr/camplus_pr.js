 jQuery(function($){ // select change show notice.
 			$('#fgm_node_purchase_request_form_group_budgets-add-more-wrapper select').change(function(){
			  	if($(this).parents('tr').find('input').attr('placeholder',Drupal.settings.camplus_pr[$(this).context.value])) {
			  		// $(this).parents('.fieldset-wrapper').prepend('<div id="op-notice" class="messages warning" style="display: block; ">* Please click \'Filter\' to see your changes, and if the filter button is not here: Please click \'Refine\' to see your changes.</div>');
			  		
			  	}
			});
 			$('#edit-field-pr-sole-supplier-und').change(function() {
			     if(this.checked) {
			         // do something when checked
			        $('#fgm_node_purchase_request_form_group_ref_supplier-add-more-wrapper').slideUp();
			     }else {
			     	$('#fgm_node_purchase_request_form_group_ref_supplier-add-more-wrapper').slideDown();
			     }
			 });
 			$('#edit-field-pr-for-tender-und').change(function() {
			     if(this.checked) {
			         // do something when checked
			        $('#fgm_node_purchase_request_form_group_ref_supplier-add-more-wrapper').slideUp();
			     }else {
			     	$('#fgm_node_purchase_request_form_group_ref_supplier-add-more-wrapper').slideDown();
			     }
			 });
	Drupal.behaviors.pr = {
		attach: function(context, settings) {
			$('#fgm_node_purchase_request_form_group_budgets-add-more-wrapper select').change(function(){
			  	if($(this).parents('tr').find('input').attr('placeholder',Drupal.settings.camplus_pr[$(this).context.value])) {
			  	}
			});

			$(".form-item-fgm-node-purchase-request-form-group-chosen-fields-items-0-field-chosen-price-und-value input").attr("disabled","disabled");
			countTotalBI();
			function countTotalBInoblur() {
				$('#fgm-node-purchase-request-form-group-budgets-values input').each(function(){
					total = 0;
					$('#fgm-node-purchase-request-form-group-budgets-values input').each(function(){
						if($(this).val()<0) $(this).val(0);
						total += parseFloat($(this).val()) || 0;
					});
					if($('#edit-field-payment-from-students input').val()<0)$('#edit-field-payment-from-students input').val(0);
					total += parseFloat($('#edit-field-payment-from-students input').val()|| 0);
					$('.multiple-field-chosen-price input').val(total);
				});
			}

			$('#edit-field-payment-from-students input').blur(function(){
				countTotalBInoblur();
			});
			$('input[value=Save]').click(function(e){
				// e.preventDefault();
				countTotalBInoblur();
			});
			
			if($('#edit-fgm-node-purchase-request-form-group-budgets-fields-items-1-field-budget-items-amount-und-value').length != 0) {
				$('#field-multiple-bi-reason-add-more-wrapper').show();
			}
			// jQuery(document).ready(function () {
			// 	console.log('show?3	');
			// 	jQuery('#edit-fgm-node-purchase-request-form-group-budgets-add-more').click(function(){
					
			// 		jQuery('#edit-fgm-node-purchase-request-form-group-budgets-add-more').hide();
			// 		console.log('show?4');
			// 	});
			// });

				
		}
	}
	
	$(".form-item-fgm-node-purchase-request-form-group-chosen-fields-items-0-field-chosen-price-und-value input").attr("disabled","disabled");
	function countTotalBI() {
		$('#fgm-node-purchase-request-form-group-budgets-values input').blur(function(){
			total = 0;
			$('#fgm-node-purchase-request-form-group-budgets-values input').each(function(){
				if($(this).val()<0) $(this).val(0);
				total += parseFloat($(this).val()) || 0;
			});
			if($('#edit-field-payment-from-students input').val()<0)$('#edit-field-payment-from-students input').val(0);
			total += parseFloat($('#edit-field-payment-from-students input').val()|| 0);
			$('.multiple-field-chosen-price input').val(total);
		});
	}
	countTotalBI();
	function countTotalBInoblur() {
		$('#fgm-node-purchase-request-form-group-budgets-values input').each(function(){
			total = 0;
			$('#fgm-node-purchase-request-form-group-budgets-values input').each(function(){
				if($(this).val()<0) $(this).val(0);
				total += parseFloat($(this).val()) || 0;
			});
			if($('#edit-field-payment-from-students input').val()<0)$('#edit-field-payment-from-students input').val(0);
			total += parseFloat($('#edit-field-payment-from-students input').val()|| 0);
			$('.multiple-field-chosen-price input').val(total);
		});
	}

	$('#edit-field-payment-from-students input').blur(function(){
		countTotalBInoblur();
	});
	$('input[value=Save]').click(function(e){
		// e.preventDefault();
		countTotalBInoblur();
	});
	// field_multiple_bi_reason
	// console.log($('#edit-fgm-node-purchase-request-form-group-budgets-fields-items-1-field-budget-items-amount-und-value').val());
	if($('#edit-fgm-node-purchase-request-form-group-budgets-fields-items-1-field-budget-items-amount-und-value').length == 0) {
		$('#field-multiple-bi-reason-add-more-wrapper').hide();
	}
});
