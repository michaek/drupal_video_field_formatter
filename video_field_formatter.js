(function ($) {

  Drupal.behaviors.video_field_formatter = {
    attach: function (context, settings) {
      
      $.each(settings.video_field_formatter, function(dom_id){
        var options = {
          flashplayer: settings.video_field_formatter_jwplayer_url, 
          file: this.url
        };
        
        // Provide width and height options if they're set.
        if (this.video_width && this.video_height) {
          options.width = this.video_width;
          options.height = this.video_height;
        }
        
        // Make sure we're not initializing the player outside this context.
        $('#'+dom_id, context).each(function(){
          jwplayer(this.id).setup(options);
        });
      });
      
    }
  };

})(jQuery);