function love.draw()
	for x = 0, 10 do
		for y = 0, 10 do
			love.graphics.setColor(1/x, 1/y, 1/x*10)
			love.graphics.rectangle("fill", 100+x*30, 100+y*30, 20, 20)
		end
	end
end