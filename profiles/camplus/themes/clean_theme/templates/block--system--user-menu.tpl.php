<ul class="secondary-menu unstyled clearfix fl">
  <li><a href="<?php print url('user'); ?>"><i class="icon ir icon-account">User</i></a></li>

  
<?php if(module_exists('privatemsg')):?>
  <li><a href="<?php print url('messages'); ?>"><i class="icon ir icon-msg">Message</i></a><i class="msg-num">
  <?php print privatemsg_unread_count(); ?></i></li>
<?php endif; ?>
  
  
  
  <li><a href="<?php print url('user/logout'); ?>"><i class="icon ir icon-logout">Logout</i></a></li>
</ul>