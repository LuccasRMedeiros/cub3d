<h1>Cub3D Draw</h2>
<h2>Window control and rendering functions</h2>
<br>
<p>Under Draw module there are functions to render tiles and sprites on the screen, also controling the resolution they are been exhibited. The click on exit button and press esc key events are handled here, but the other key and mouse events are under Core module.</p>
<br>
<p>While it need to draw things correctly on the screen, it must have a function to cast rays, so first of all we must understand how those rays are casted. From the point where the player is on the map it is needed that we find the first x and y point a ray hits, so we keep its trajetory till it finds a wall. using the traveling distance from the original point to the point it hit a wall we can calculate the height of the same wall in the player perspective. To do so, we can use orthogonality to calculate its trajectory. With the trajetory terminated, we finally have the distance so now we can calculate the height of a column of pixels.</p>
