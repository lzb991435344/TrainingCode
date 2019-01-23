--! @brief      初始化牌组
--! @return     { description_of_the_return_value }
--! @author     kun si
--! @date       2017-07-31
local function initCard()
	local cardsList = {}

	for i = 14, 15 do
		local tmpCard={value=i, color=0}
		table.insert(cardsList, tmpCard)
	end

	for i = 1, 4 do
		for j = 1, 13 do
			local tmpCard={value=j, color=i}
			table.insert(cardsList, tmpCard)
		end
	end
	return cardsList
end

--! @brief      洗牌
--! @param      cardsList  The cards list
--! @return     { description_of_the_return_value }
--! @author     kun si
--! @date       2017-07-31
local function shuffleCards(cardsList)
	math.randomseed(tostring(os.time()):reverse():sub(1, 7))
	local shuffleTime = math.random(300, 540)
	--print("shuffleTime", shuffleTime)
	for i = 1, shuffleTime do
		local tmpCard = {}
		card1 = math.random(1, 54)
		card2 = math.random(1, 54)
		while card1 == card2 do
            card2 = math.random(1, 54)
        end
        --print("card", card1, card2)
		tmpCard = cardsList[card1]
		cardsList[card1] = cardsList[card2]
		cardsList[card2] = tmpCard
	end
	return cardsList
end

--! @brief      发牌
--! @param      cardsList  The cards list
--! @return     { description_of_the_return_value }
--! @author     kun si
--! @date       2017-07-31
local function dealer(cardsList)

	local players = {}
	for i = 1, 5 do
		for j = 1, 6 do
			if not players[j] then
				players[j] = {}
			end
			local tmpCard = table.remove(cardsList)
			table.insert(players[j], tmpCard)
		end 
	end
	return players
end

local cardsList = initCard()

cardsList = shuffleCards(cardsList)

local players = dealer(cardsList)


for k, v in ipairs(players) do
	print(string.format("玩家%d手牌为：", k))
	for k1, v2 in ipairs(v) do
		print(v2.value, v2.color)
	end
end



