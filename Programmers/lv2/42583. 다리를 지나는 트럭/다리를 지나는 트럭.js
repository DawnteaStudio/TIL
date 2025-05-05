
function solution(bridge_length, weight, truck_weights) {
    var answer = 0;
    let bridge = [];
    let bridgeWeight = 0;

    while (truck_weights.length > 0 || bridge.length > 0) {
        if (bridge.length > 0 && bridge[0].time === bridge_length) {
            const truck = bridge.shift();
            bridgeWeight -= truck.weight;
        }

        if (truck_weights.length > 0 && bridgeWeight + truck_weights[0] <= weight) {
            const truckWeight = truck_weights.shift();
            bridge.push({ weight: truckWeight, time: 0 });
            bridgeWeight += truckWeight;
        }

        bridge.forEach((truck) => {
            truck.time++;
        });

        answer++;
    }

    return answer;
}
