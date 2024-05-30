package org.example.service.implementations;

import org.example.service.DeliveryService;
import org.example.service.Report;

public class ReportServiceImplementation implements Report {
    private DeliveryService deliveryService;



    @Override
    public int successfulDeliveries() {
        return 0;
    }
}
