function love.draw()
	for x = 0, 10 do
		for y = 0, 10 do
			love.graphics.rectangle(100+x*30, 100+y*30, 20, 20)
		end
	end
end