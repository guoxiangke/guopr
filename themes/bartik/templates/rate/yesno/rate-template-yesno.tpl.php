<?php
/**
 * @file
 * Rate widget theme
 *
 * This is the default template for rate widgets. See section 3 of the README
 * file for information on theming widgets.
 *
 * Available variables:
 * - $links: Array with vote links
 *     array(
 *       array(
 *         'text' => 'Button label',
 *         'href' => 'Link href',
 *         'value' => 20,
 *         'votes' => 6,
 *       ),
 *     )
 * - $results: Array with voting results
 *     array(
 *       'rating' => 12, // Average rating
 *       'options' => array( // Votes per option. Only available when value_type == 'options'
 *         1 => 234,
 *         2 => 34,
 *       ),
 *       'count' => 23, // Number of votes
 *       'up' => 2, // Number of up votes. Only available for thumbs up / down.
 *       'down' => 3, // Number of down votes. Only available for thumbs up / down.
 *       'up_percent' => 40, // Percentage of up votes. Only available for thumbs up / down.
 *       'down_percent' => 60, // Percentage of down votes. Only available for thumbs up / down.
 *       'user_vote' => 80, // Value for user vote. Only available when user has voted.
 *     )
 * - $mode: Display mode.
 * - $just_voted: Indicator whether the user has just voted (boolean).
 * - $content_type: "node" or "comment".
 * - $content_id: Node or comment id.
 * - $buttons: Array with themed buttons (built in preprocess function).
 * - $info: String with user readable information (built in preprocess function).
 */
$feed_back_title = $info?$info:$display_options['description'];
$feed_back_buttons = '<div class="pr-rate-buttons">
  <span class = "pr-rate">
     '.theme('rate_button', array(
      'text' => $links[0]['text'],
      'href' => $links[0]['href'],
      'class' => "approve-btn")
    ).'
  </span>
  <span class = "pr-rate">
    '.theme('rate_button', array(
      'text' => $links[1]['text'],
      'href' => $links[1]['href'],
      'class' => "disapprove-btn")
    ).'
  </span>
</div>';
    $widgets = rate_get_active_widgets('node', 'purchase_request');
    foreach ($widgets as $widget_id => $widget) {
      //没有权限时，清楚rate
      $widget->id = $widget_id;
      //一旦审核通过，所有审批部门角色不可更改即 not show rate.

      if($widget->name == 'approve') {
        $rate_results = rate_get_results('node', $content_id, $widget->id);
        if(isset($rate_results['user_vote'])) {
          $feed_back_buttons = '';
        }
        break;
      }
    }

?>

<?php // print theme('item_list', array('items' => $buttons)); ?>

<?php if ($display_options['description']): ?>
  
<?php endif; ?>

<p class="fed_button btn btn-mini btn-link"><?php print $feed_back_title;?></p>

<?php print $feed_back_buttons; ?>

<?php 
//old version
/**
 * <?php // print theme('item_list', array('items' => $buttons)); ?>
<div>
  <span class = "qa-useful">
     <?php print  theme('rate_button', array(
      'text' => $links[0]['text'],
      'href' => $links[0]['href'],
      'class' => "qa-useful-yes")
    ); ?>
  </span>
  <span class = "qa-useful">
     <?php print  theme('rate_button', array(
      'text' => $links[1]['text'],
      'href' => $links[1]['href'],
      'class' => "qa-useful-no")
    ); ?>
  </span>
</div>
<?php if ($info): ?>
  <?php print '<div class="rate-info">' . $info . '</div>'; ?>
<?php endif; ?>

<?php if ($display_options['description']): ?>
  <?php print '<div class="rate-description">' . $display_options['description'] . '</div>'; ?>
<?php endif; ?>

 */
?>
