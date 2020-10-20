
<?php 
    
    // Set the vertices of polygon 
    $values = array( 
                150,  50, // Point 1 (x, y) 
                50, 250,  // Point 2 (x, y) 
                250,  250 // Point 3 (x, y) 
            ); 
          
    // Create the size of image or blank image 
    $image = imagecreatetruecolor(300, 300); 
        
    // Set the background color of image 
    $background_color = imagecolorallocate($image,  0, 153, 0); 
         
    // Fill background with above selected color 
    imagefill($image, 0, 0, $background_color); 
       
    // Allocate a color for the polygon 
    $image_color = imagecolorallocate($image, 255, 255, 255); 
         
    // Draw the polygon 
    imagepolygon($image, $values, 3, $image_color); 
         
    // Output the picture to the browser 
    header('Content-type: image/png'); 
         
    imagepng($image); 
    ?> 
    