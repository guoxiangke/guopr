<?php
/**
 * @file 
 * Template to display the date box in a calendar.
 *
 * - $view: The view.
 * - $granularity: The type of calendar this box is in -- year, month, day, or week.
 * - $mini: Whether or not this is a mini calendar.
 * - $class: The class for this box -- mini-on, mini-off, or day.
 * - $day:  The day of the month.
 * - $date: The current date, in the form YYYY-MM-DD.
 * - $link: A formatted link to the calendar day view for this day.
 * - $url:  The url to the calendar day view for this day.
 * - $selected: Whether or not this day has any items.
 * - $items: An array of items for this day.
 */
if($view->name == 'book_calendar' && $view->current_display == 'page_1') {
	?>
	<?php if (isset($add_event_link)): ?>
  <span class="add-event-link"><?php print $add_event_link; ?></span>
	<?php endif; ?>
	<div class="<?php print $granularity ?> <?php print $class; ?>"> <?php print !empty($selected) ? $link : $day; ?> </div>
	<?php
}else{
?>
<?php if (isset($add_event_link)): ?>
<a href="/node/add/reservation/<?php echo $date;?>">
<?php endif;?>
<div class="<?php print $granularity ?> <?php print $class; ?>"> <?php print !empty($selected) ? $link : $day; ?> </div>
<?php if (isset($add_event_link)): ?>
</a>
<?php endif;?>
<?php
}
?>

